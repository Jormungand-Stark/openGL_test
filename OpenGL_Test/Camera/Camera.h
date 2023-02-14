//
//  Camera.h
//  OpenGL_Test
//
//  Created by Jormungand on 2022/12/12.
//

#ifndef Camera_h
#define Camera_h

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

// 定义相机移动的几个可能选项
enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

// 部分属性默认值
const float YAW         = -90.0f; // 当俯仰角和偏航角都为0时，摄像机方向是指向X轴正方向的，因此需要设偏航角为-90，摄像机方向才能指向z轴负方向，与上述一致。
const float PITCH       =  0.0f;
const float SPEED       =  2.5f;
const float SENSITIVITY =  0.1f;
const float FOV         =  45.0f;

// 抽象的相机类
class Camera
{
public:
    glm::vec3 Position; // 摄像机位置
    glm::vec3 Front; // 同z负轴的方向向量
    glm::vec3 Up; // 上向量
    glm::vec3 Right;
    glm::vec3 WorldUp; // 世界坐标上向量

    float Yaw;
    float Pitch;

    float MovementSpeed;
    float MouseSensitivity;
    float Fov;

    // 通过vec3构造
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Fov(FOV)
    {
        Position = position;
        WorldUp = up;
        Yaw = yaw;
        Pitch = pitch;
        updateCameraVectors();
    }
    
    // 通过float构造
    Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Fov(FOV)
    {
        Position = glm::vec3(posX, posY, posZ);
        WorldUp = glm::vec3(upX, upY, upZ);
        Yaw = yaw;
        Pitch = pitch;
        updateCameraVectors();
    }

    // 返回使用欧拉角和LookAt矩阵计算的视图矩阵
    glm::mat4 GetViewMatrix()
    {
        return glm::lookAt(Position, Position + Front, Up);
    }

    // 处理键盘的输入
    void ProcessKeyboard(Camera_Movement direction, float deltaTime)
    {
        float velocity = MovementSpeed * deltaTime;
        if (direction == FORWARD)
            Position += Front * velocity;
        if (direction == BACKWARD)
            Position -= Front * velocity;
        if (direction == LEFT)
            Position -= Right * velocity;
        if (direction == RIGHT)
            Position += Right * velocity;
//        Position.y = 0;
    }

    // 处理鼠标的输入
    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true)
    {
        xoffset *= MouseSensitivity;
        yoffset *= MouseSensitivity;

        /** 2.把偏移量添加到摄像机的俯仰角和偏航角中 **/
        Yaw   += xoffset;
        Pitch += yoffset;

        /** 3.对偏航角和俯仰角进行最大和最小值的限制 **/
        // 确保当pitch超出界限时，屏幕不会翻转
        if (constrainPitch)
        {
            if (Pitch > 89.0f)
                Pitch = 89.0f;
            if (Pitch < -89.0f)
                Pitch = -89.0f;
        }

        /** 4.计算方向向量 **/
        // update Front, Right and Up Vectors using the updated Euler angles
        updateCameraVectors();
    }

    // 处理鼠标滚轮的输入
    void ProcessMouseScroll(float yoffset)
    {
        Fov -= (float)yoffset;
        if (Fov < 1.0f)
            Fov = 1.0f;
        if (Fov > 45.0f)
            Fov = 45.0f;
    }
    
    // Custom implementation of the LookAt function
    glm::mat4 calculate_lookAt_matrix(glm::vec3 position, glm::vec3 target, glm::vec3 worldUp)
    {
        // 1. Position = known
        // 2. Calculate cameraDirection
        glm::vec3 zaxis = glm::normalize(position - target);
        // 3. Get positive right axis vector
        glm::vec3 xaxis = glm::normalize(glm::cross(glm::normalize(worldUp), zaxis));
        // 4. Calculate camera up vector
        glm::vec3 yaxis = glm::cross(zaxis, xaxis);

        // Create translation and rotation matrix
        // In glm we access elements as mat[col][row] due to column-major layout
        glm::mat4 translation = glm::mat4(1.0f); // Identity matrix by default
        translation[3][0] = -position.x; // Third column, first row
        translation[3][1] = -position.y;
        translation[3][2] = -position.z;
        glm::mat4 rotation = glm::mat4(1.0f);
        rotation[0][0] = xaxis.x; // First column, first row
        rotation[1][0] = xaxis.y;
        rotation[2][0] = xaxis.z;
        rotation[0][1] = yaxis.x; // First column, second row
        rotation[1][1] = yaxis.y;
        rotation[2][1] = yaxis.z;
        rotation[0][2] = zaxis.x; // First column, third row
        rotation[1][2] = zaxis.y;
        rotation[2][2] = zaxis.z;

        // Return lookAt matrix as combination of translation and rotation matrix
        return rotation * translation; // Remember to read from right to left (first translation then rotation)
    }


private:
    // 根据摄影机最新的Euler角度计算Front、Right、Up向量
    void updateCameraVectors()
    {
        // calculate the new Front vector
        glm::vec3 front;
        front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        front.y = sin(glm::radians(Pitch));
        front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        Front = glm::normalize(front);
        // also re-calculate the Right and Up vector
        Right = glm::normalize(glm::cross(Front, WorldUp));  // 归一化，因为鼠标向上/向下移动得越多，长度就越接近0，这会导致移动速度变慢。
        Up    = glm::normalize(glm::cross(Right, Front));
    }
};

#endif /* Camera_h */

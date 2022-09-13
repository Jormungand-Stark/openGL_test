#version 330 core
out vec4 FragColor;
//in vec3 ourColor;
in vec3 our_position;

void main()
{
    // 注意位置值如何线性插值以获得所有不同的颜色
    FragColor = vec4(our_position, 1.0);
}

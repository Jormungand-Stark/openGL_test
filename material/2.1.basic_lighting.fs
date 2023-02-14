/* 在世界空间进行光照计算 */
//#version 330 core
//out vec4 FragColor;
//
//in vec3 Normal;
//in vec3 FragPos;
//
//uniform vec3 lightPos;
//uniform vec3 viewPos;
//uniform vec3 lightColor;
//uniform vec3 objectColor;
//
//void main()
//{
//    // ambient
//    float ambientStrength = 0.1;
//    vec3 ambient = ambientStrength * lightColor;
//
//    // diffuse
//    /* 归一化法向量和光线方向向量以简化计算，忘记对向量进行标准化是一个十分常见的错误。 */
//    vec3 norm = normalize(Normal);
//    // 光的方向向量是光源位置向量与片段位置向量之间的向量差。
//    vec3 lightDir = normalize(lightPos - FragPos);
//    /* normalize end */
//    // 如果两个向量之间的角度大于90度，点乘的结果就会变成负数（cos90+ < 0），负数颜色的光照是没有定义的。因此使用max函数保证漫反射分量不会变成负数。
//    float diff = max(dot(norm, lightDir), 0.0);
//    vec3 diffuse = diff * lightColor;
//
//    // specular
//    float specularStrength = 0.5; // 高光强度中等
//    vec3 viewDir = normalize(viewPos - FragPos); // 视线方向向量
//    vec3 reflectDir = reflect(-lightDir, norm); // 光的反射向量
//    /*
//     * reflect函数要求第一个向量是从光源指向片段位置的向量，
//     * 但是lightDir正好相反，是从片段指向光源（由先前计算lightDir向量时，减法的顺序决定）。
//     * 因此通过对lightDir向量取反来获得相反的方向。
//     * 第二个参数要求是一个法向量，所以提供的是已标准化的norm向量。
//     */
//    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
//    vec3 specular = specularStrength * spec * lightColor;
//
//    // 物体最终颜色
//    vec3 result = (ambient + diffuse + specular) * objectColor;
//    FragColor = vec4(result, 1.0);
//}

/* 在观察空间进行光照计算 */
//#version 330 core
//out vec4 FragColor;
//
//in vec3 FragPos;
//in vec3 Normal;
//in vec3 LightPos;   // extra in variable, since we need the light position in view space we calculate this in the vertex shader
//
//uniform vec3 lightColor;
//uniform vec3 objectColor;
//
//void main()
//{
//    // ambient
//    float ambientStrength = 0.1;
//    vec3 ambient = ambientStrength * lightColor;
//    
//     // diffuse
//    vec3 norm = normalize(Normal);
//    vec3 lightDir = normalize(LightPos - FragPos);
//    float diff = max(dot(norm, lightDir), 0.0);
//    vec3 diffuse = diff * lightColor;
//    
//    // specular
//    float specularStrength = 0.5;
//    vec3 viewDir = normalize(-FragPos); // the viewer is always at (0,0,0) in view-space, so viewDir is (0,0,0) - Position => -Position
//    vec3 reflectDir = reflect(-lightDir, norm);
//    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
//    vec3 specular = specularStrength * spec * lightColor;
//    
//    vec3 result = (ambient + diffuse + specular) * objectColor;
//    FragColor = vec4(result, 1.0);
//}

/* 使用顶点着色器进行光照计算 */
#version 330 core
out vec4 FragColor;

in vec3 LightingColor;

uniform vec3 objectColor;

void main()
{
   FragColor = vec4(LightingColor * objectColor, 1.0);
}

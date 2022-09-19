#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

// texture sampler
uniform sampler2D texture1;

void main()
{
//    FragColor = texture(texture1, TexCoord);
    // 把纹理颜色与顶点颜色在片段着色器中相乘来混合二者的颜色：
    FragColor = texture(texture1, TexCoord) * vec4(ourColor, 1.0);
}

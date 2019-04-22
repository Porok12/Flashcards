#version 330

in vec2 texCoords;

uniform sampler2D texture;

void main()
{
    gl_FragColor = vec4(1.0, 1.0, 1.0, texture2D(texture, texCoords).r);
}

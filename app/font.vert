#version 330

layout (location = 0) in vec4 coords;

out vec2 texCoords;

uniform mat4 projection;

void main()
{
    gl_Position = projection * vec4(coords.xy, 0.0, 1.0);
    texCoords = coords.zw;
}

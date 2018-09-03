#version 330

layout (location = 0) in vec3 pos;

uniform mat4 mv_matrix;
uniform mat4 project_matrix;

void main()
{
    gl_Position = project_matrix * mv_matrix * vec4(pos.x, pos.y, pos.z, 1.0);
}

#version 330

in vec2 UVs;

uniform sampler2D tex;

void main(void)
{
    gl_FragColor = texture(tex, UVs);
    //vec4(0.6, 0.4, 0.5, 1.0);
}

#version 330

in vec2 UVs;

uniform sampler2D tex;

void main(void)
{
    if(gl_FrontFacing)
        gl_FragColor = texture(tex, UVs);
    else
        gl_FragColor = texture(tex, vec2(1.0 - UVs.x, UVs.y)); //vec4(0.6, 0.4, 0.5, 1.0);
}

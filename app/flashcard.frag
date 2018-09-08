#version 330

in vec3 oPos;

uniform sampler2D tex;

void main(void)
{
    gl_FragColor = texture(tex, vec2(oPos.x, oPos.y));
    //vec4(0.6, 0.4, 0.5, 1.0);
}

import QtQuick 2.0

ShaderEffect {
    id:layer
    property variant source: ShaderEffectSource { sourceItem: video; hideSource: true }
    property real wiggleAmount: 0.1
    anchors.fill: root

    fragmentShader: "
        varying highp vec2 qt_TexCoord0;
        uniform sampler2D source;
        uniform highp float wiggleAmount;
        void main(void)
        {
            highp vec2 wiggledTexCoord = qt_TexCoord0;
            wiggledTexCoord.s += sin(4.0 * 3.141592653589 * wiggledTexCoord.t) * wiggleAmount;
            gl_FragColor = texture2D(source, wiggledTexCoord.st);
        }
    "
}

import QtQuick 2.0
import QtMultimedia 5.0

VideoOutput {
    id: layer
    source: mediaPlayer
    property alias mediaSource: mediaPlayer.source
    property alias volume: mediaPlayer.volume

    MediaPlayer {
        id: mediaPlayer
        autoPlay: true
        volume: 0.5
        loops: Audio.Infinite

        onStopped: play()
    }

    function play() { mediaPlayer.play() }
    function stop() { mediaPlayer.stop() }
}

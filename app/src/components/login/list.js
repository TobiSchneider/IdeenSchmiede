import React, { Component } from 'react';
import { Alert, AppRegistry, Platform, StyleSheet, Text, TouchableHighlight, TouchableOpacity, TouchableNativeFeedback, TouchableWithoutFeedback, View } from 'react-native';

export default class Touchables extends Component {
  _onPressButtonColor() {
  //  Alert.alert('You tapped the button!')
  }
  _onPressButtonBrightness() {
  //  Alert.alert('You tapped the button!')
  }
  _onPressButtonModus() {
  //  Alert.alert('You tapped the button!')
  }
  _onPressButtonConnect() {
  //  Alert.alert('You tapped the button!')
  }



  render() {
    return (
      <View style={styles.container}>
        <TouchableOpacity onPress={this._onPressButtonColor} underlayColor="white">
          <View style={styles.button}>
            <Text style={styles.buttonText}>Farbe ändern</Text>
          </View>
        </TouchableOpacity>
        <TouchableOpacity onPress={this._onPressButtonBrightness}>
          <View style={styles.button}>
            <Text style={styles.buttonText}>Helligkeit ändern</Text>
          </View>
        </TouchableOpacity>
        <TouchableOpacity
            onPress={this._onPressButtonModus}
            background={Platform.OS === 'android' ? TouchableNativeFeedback.SelectableBackground() : ''}>
          <View style={styles.button}>
            <Text style={styles.buttonText}>Modus ändern</Text>
          </View>
        </TouchableOpacity>
        <TouchableOpacity
            onPress={this._onPressButtonConnect}
            >
          <View style={styles.button}>
            <Text style={styles.buttonText}>Mit Uhr verbinden</Text>
          </View>
        </TouchableOpacity>
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    paddingTop: 60,
    alignItems: 'center'
  },
  button: {
    marginBottom: 10,
    width: 260,
    alignItems: 'center',
    backgroundColor: '#2196F3'
  },
  buttonText: {
    padding: 20,
    color: 'white'
  }
})

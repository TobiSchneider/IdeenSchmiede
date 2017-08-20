import React, { Component } from 'react';
import { Alert, AppRegistry, Platform, StyleSheet, Text, TouchableHighlight, TouchableOpacity, TouchableNativeFeedback, TouchableWithoutFeedback, View } from 'react-native';

export default class Touchables extends Component {
  _onPressButtonFade() {
    fetch('http://esp8266.local/frans/a')
  }
  _onPressButtonEinschieben() {
    fetch('http://esp8266.local/frans/b')
  }
  _onPressButtonHart() {
    fetch('http://esp8266.local/frans/c')
  }

  render() {
    return (
      <View style={styles.container}>
        <TouchableOpacity onPress={this._onPressButtonFade} underlayColor="white">
          <View style={styles.button}>
            <Text style={styles.buttonText}>Fade</Text>
          </View>
        </TouchableOpacity>
        <TouchableOpacity onPress={this._onPressButtonEinschieben}>
          <View style={styles.button}>
            <Text style={styles.buttonText}>Einschieben</Text>
          </View>
        </TouchableOpacity>
        <TouchableOpacity
            onPress={this._onPressButtonHart}
            background={Platform.OS === 'android' ? TouchableNativeFeedback.SelectableBackground() : ''}>
          <View style={styles.button}>
            <Text style={styles.buttonText}>Hart</Text>
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
    marginBottom: 30,
    width: 260,
    alignItems: 'center',
    backgroundColor: 'rgba(44, 62, 80,1.0)'
  },
  buttonText: {
    padding: 20,
    color: 'white'
  }
})

import React, { Component } from 'react';
import { Alert, AppRegistry, Platform, StyleSheet, Text, TouchableHighlight, TouchableOpacity, TouchableNativeFeedback, TouchableWithoutFeedback, View } from 'react-native';

export default class Touchables extends Component {
  _onPressButtonPlus() {
    fetch('http://esp8266.local/timea/p')
  }
  _onPressButtonMinus() {
    fetch('http://esp8266.local/times/m')
  }
  _onPressButtonReset() {
    fetch('http://esp8266.local/times/r')
  }




  render() {
    return (
      <View style={styles.container}>
        <TouchableOpacity onPress={this._onPressButtonPlus} underlayColor="white">
          <View style={styles.button}>
            <Text style={styles.buttonText}>+ 1 Stunde</Text>
          </View>
        </TouchableOpacity>
        <TouchableOpacity onPress={this._onPressButtonMinus}>
          <View style={styles.button}>
            <Text style={styles.buttonText}>- 1 Stunde</Text>
          </View>
        </TouchableOpacity>
        <TouchableOpacity onPress={this._onPressButtonReset}>
          <View style={styles.button}>
            <Text style={styles.buttonText}>Reset</Text>
          </View>
        </TouchableOpacity>
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    paddingTop: 200,
    alignItems: 'center'
  },
  button: {
    marginBottom: 30,
    width: 300,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: 'rgba(44, 62, 80,1.0)'
  },
  buttonText: {
    padding: 20,
    color: 'white'
  }
})

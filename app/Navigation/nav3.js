import React, { Component } from 'react';
import { Alert, AppRegistry, Platform, StyleSheet, Text, TouchableHighlight, TouchableOpacity, TouchableNativeFeedback, TouchableWithoutFeedback, View, AsyncStorage } from 'react-native';

export default class Touchables extends Component {

  _onPressButtonPlus() {
    var requestString = global.gotEEM  + "/timea/p";
    fetch(requestString)
  }
  _onPressButtonMinus() {
    var requestString = global.gotEEM  + "/timea/m";
    fetch(requestString)
  }
  _onPressButtonReset() {
    var requestString = global.gotEEM  + "/timea/r";
    fetch(requestString)
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

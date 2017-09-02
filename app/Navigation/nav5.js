import React, { Component } from 'react';
import { Alert, AppRegistry, Platform, StyleSheet, Text, TouchableHighlight, TouchableOpacity, TouchableNativeFeedback, TouchableWithoutFeedback, View, AsyncStorage } from 'react-native';

export default class Touchables extends Component {

  _onPressButtonCOLOR() {
    Alert.alert('C!')
  }
  _onPressButtonBRIGHTNESS() {
    Alert.alert('B!')
  }
  _onPressButtonTIME() {
    Alert.alert('T!')
  }
  _onPressButtonMODE() {
    Alert.alert('M!')
  }
  _onPressButtonCONNECT() {
    Alert.alert('CN!')
  }



  render() {
    return (
      <View style={styles.container}>
        <TouchableOpacity onPress={this._onPressButtonCOLOR} underlayColor="white">
          <View style={styles.button}>
            <Text style={styles.buttonText}>COLOR</Text>
          </View>
        </TouchableOpacity>
        <TouchableOpacity onPress={this._onPressButtonBRIGHTNESS}>
          <View style={styles.button}>
            <Text style={styles.buttonText}>BRIGHTNESS</Text>
          </View>
        </TouchableOpacity>
        <TouchableOpacity
            onPress={this._onPressButtonMODE}
            background={Platform.OS === 'android' ? TouchableNativeFeedback.SelectableBackground() : ''}>
          <View style={styles.button}>
            <Text style={styles.buttonText}>MODE</Text>
          </View>
        </TouchableOpacity>
        <TouchableOpacity
            onPress={this._onPressButtonTIME}
            >
          <View style={styles.button}>
            <Text style={styles.buttonText}>TTIME</Text>
          </View>
        </TouchableOpacity>
        <TouchableOpacity onPress={this._onPressButtonCONNECT} onLongPress={this._onLongPressButton} underlayColor="white">
          <View style={styles.button}>
            <Text style={styles.buttonText}>CONNECT</Text>
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

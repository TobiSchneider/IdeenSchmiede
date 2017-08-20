import React, { Component } from 'react';
import { Alert, AppRegistry, Platform, StyleSheet, Text, TouchableHighlight, TouchableOpacity, TouchableNativeFeedback, TouchableWithoutFeedback, View, ScrollView } from 'react-native';

export default class Touchables extends Component {
  _onPressButton_100() {
    fetch('http://esp8266.local/brightness/255')
  }
  _onPressButton_80() {
    fetch('http://esp8266.local/brightness/200')
  }
  _onPressButton_60() {
    fetch('http://esp8266.local/brightness/150')
  }
  _onPressButton_40() {
    fetch('http://esp8266.local/brightness/100')
  }
  _onPressButton_20() {
    fetch('http://esp8266.local/brightness/50')
  }
  _onPressButton_10() {
    fetch('http://esp8266.local/brightness/25')
  }
  _onPressButton_5() {
    fetch('http://esp8266.local/brightness/12')
  }
  _onPressButton_1() {
    fetch('http://esp8266.local/brightness/1')
  }



  render() {
    return (
      <ScrollView>
      <View style={styles.container}>
        <TouchableOpacity onPress={this._onPressButton_100} underlayColor="white">
          <View style={styles.button}>
            <Text style={styles.buttonText}>100%</Text>
          </View>
        </TouchableOpacity>
        <TouchableOpacity onPress={this._onPressButton_80}>
          <View style={styles.button}>
            <Text style={styles.buttonText}>80%</Text>
          </View>
        </TouchableOpacity>
        <TouchableOpacity
            onPress={this._onPressButton_60}
            background={Platform.OS === 'android' ? TouchableNativeFeedback.SelectableBackground() : ''}>
          <View style={styles.button}>
            <Text style={styles.buttonText}>60%</Text>
          </View>
        </TouchableOpacity>
        <TouchableOpacity
            onPress={this._onPressButton_40}
            >
          <View style={styles.button}>
            <Text style={styles.buttonText}>40%</Text>
          </View>
        </TouchableOpacity>
        <TouchableOpacity onPress={this._onPressButton_20} onLongPress={this._onLongPressButton} underlayColor="white">
          <View style={styles.button}>
            <Text style={styles.buttonText}>20%</Text>
          </View>

        </TouchableOpacity>
        <TouchableOpacity onPress={this._onPressButton_10} onLongPress={this._onLongPressButton} underlayColor="white">
          <View style={styles.button}>
            <Text style={styles.buttonText}>10%</Text>
          </View>
        </TouchableOpacity>

        <TouchableOpacity onPress={this._onPressButton_5} onLongPress={this._onLongPressButton} underlayColor="white">
          <View style={styles.button}>
            <Text style={styles.buttonText}>5%</Text>
          </View>
        </TouchableOpacity>

        <TouchableOpacity onPress={this._onPressButton_1} onLongPress={this._onLongPressButton} underlayColor="white">
          <View style={styles.button}>
            <Text style={styles.buttonText}>1%</Text>
          </View>
        </TouchableOpacity>

      </View>
      </ScrollView>
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

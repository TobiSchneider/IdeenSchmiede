import React, { Component } from 'react';
import { Alert, AppRegistry, Image, Platform, StyleSheet, Text, TouchableHighlight, TouchableOpacity, TouchableNativeFeedback, TouchableWithoutFeedback, View, ScrollView } from 'react-native';

export default class Touchables extends Component {
  _onPressButtonNice() {
    fetch('http://esp8266.local/color/FC0C')
  }
  _onPressButtonNice2() {
    fetch('http://esp8266.local/color/FDB2')
  }
  _onPressButton1() {
  fetch('http://esp8266.local/color/FFFF')
  }
  _onPressButton2() {
  fetch('http://esp8266.local/color/056A')
  }
  _onPressButton3() {
  fetch('http://esp8266.local/color/0408')
  }
  _onPressButton4() {
  fetch('http://esp8266.local/color/87E0')
  }
  _onPressButton5() {
  fetch('http://esp8266.local/color/0460')
  }
  _onPressButton6() {
  fetch('http://esp8266.local/color/87FF')
  }
  _onPressButton7() {
  fetch('http://esp8266.local/color/0418')
  }
  _onPressButton8() {
  fetch('http://esp8266.local/color/FC1F')
  }
  _onPressButton9() {
  fetch('http://esp8266.local/color/981F')
  }
  _onPressButton10() {
  fetch('http://esp8266.local/color/FFE0')
  }
  _onPressButton11() {
  fetch('http://esp8266.local/color/FCC6')
  }
  _onPressButton12() {
  fetch('http://esp8266.local/color/FC08')
  }
  _onPressButton13() {
  fetch('http://esp8266.local/color/EA60')
  }
  _onPressButton14() {
  fetch('http://esp8266.local/color/F9E0')
  }
  _onPressButton15() {
  fetch('http://esp8266.local/color/A940')
  }




  render() {
    return (

      <ScrollView>
        <View style={styles.container}>

          <TouchableOpacity onPress={this._onPressButton1}>
          <View style={{    marginBottom: 15,
              width: 260,
              alignItems: 'center',
              borderWidth: 1,
              borderColor: '#95a5a6',
              backgroundColor: '#ecf0f1'}}>
            <Text style={styles.buttonText}>PRESS ME!</Text>
          </View>

          </TouchableOpacity>
          <TouchableOpacity onPress={this._onPressButtonNice2}>
          <View style={{    marginBottom: 15,
              width: 260,
              alignItems: 'center',
              borderWidth: 1,
              borderColor: '#95a5a6',
              backgroundColor: '#ffd6c1'}}>
            <Text style={styles.buttonText}>PRESS ME!</Text>
          </View>
          </TouchableOpacity>

          <TouchableOpacity onPress={this._onPressButtonNice}>
          <View style={{    marginBottom: 15,
              width: 260,
              alignItems: 'center',
              borderWidth: 1,
              borderColor: '#95a5a6',
              backgroundColor: '#ffb591'}}>
            <Text style={styles.buttonText}>PRESS ME!</Text>
          </View>
          </TouchableOpacity>

          <TouchableOpacity onPress={this._onPressButton2}>
          <View style={{    marginBottom: 15,
              width: 260,
              alignItems: 'center',
              borderWidth: 1,
              borderColor: '#95a5a6',
              backgroundColor: 'rgb(26, 188, 156)'}}>
            <Text style={styles.buttonText}>PRESS ME!</Text>
          </View>
          </TouchableOpacity>

          <TouchableOpacity onPress={this._onPressButton3}>
          <View style={{    marginBottom: 15,
              width: 260,
              alignItems: 'center',
              borderWidth: 1,
              borderColor: '#95a5a6',
              backgroundColor: 'rgb(22, 160, 133)'}}>
            <Text style={styles.buttonText}>PRESS ME!</Text>
          </View>
          </TouchableOpacity>

          <TouchableOpacity onPress={this._onPressButton4}>
          <View style={{    marginBottom: 15,
              width: 260,
              alignItems: 'center',
              borderWidth: 1,
              borderColor: '#95a5a6',
              backgroundColor: 'rgb(46, 204, 113)'}}>
            <Text style={styles.buttonText}>PRESS ME!</Text>
          </View>
          </TouchableOpacity>

          <TouchableOpacity onPress={this._onPressButton5}>
          <View style={{    marginBottom: 15,
              width: 260,
              alignItems: 'center',
              borderWidth: 1,
              borderColor: '#95a5a6',
              backgroundColor: 'rgb(39, 174, 96)'}}>
            <Text style={styles.buttonText}>PRESS ME!</Text>
          </View>
          </TouchableOpacity>

          <TouchableOpacity onPress={this._onPressButton6}>
          <View style={{    marginBottom: 15,
              width: 260,
              alignItems: 'center',
              borderWidth: 1,
              borderColor: '#95a5a6',
              backgroundColor: 'rgb(52, 152, 219)'}}>
            <Text style={styles.buttonText}>PRESS ME!</Text>
          </View>
          </TouchableOpacity>

          <TouchableOpacity onPress={this._onPressButton7}>
          <View style={{    marginBottom: 15,
              width: 260,
              alignItems: 'center',
              borderWidth: 1,
              borderColor: '#95a5a6',
              backgroundColor: 'rgb(41, 128, 185)'}}>
            <Text style={styles.buttonText}>PRESS ME!</Text>
          </View>
          </TouchableOpacity>

          <TouchableOpacity onPress={this._onPressButton8}>
          <View style={{    marginBottom: 15,
              width: 260,
              alignItems: 'center',
              borderWidth: 1,
              borderColor: '#95a5a6',
              backgroundColor: 'rgb(155, 89, 182)'}}>
            <Text style={styles.buttonText}>PRESS ME!</Text>
          </View>
          </TouchableOpacity>

          <TouchableOpacity onPress={this._onPressButton9}>
          <View style={{    marginBottom: 15,
              width: 260,
              alignItems: 'center',
              borderWidth: 1,
              borderColor: '#95a5a6',
              backgroundColor: 'rgb(142, 68, 173)'}}>
            <Text style={styles.buttonText}>PRESS ME!</Text>
          </View>
          </TouchableOpacity>

          <TouchableOpacity onPress={this._onPressButton10}>
          <View style={{    marginBottom: 15,
              width: 260,
              alignItems: 'center',
              borderWidth: 1,
              borderColor: '#95a5a6',
              backgroundColor: 'rgb(241, 196, 15)'}}>
            <Text style={styles.buttonText}>PRESS ME!</Text>
          </View>
          </TouchableOpacity>

          <TouchableOpacity onPress={this._onPressButton11}>
          <View style={{    marginBottom: 15,
              width: 260,
              alignItems: 'center',
              borderWidth: 1,
              borderColor: '#95a5a6',
              backgroundColor: 'rgb(243, 156, 18)'}}>
            <Text style={styles.buttonText}>PRESS ME!</Text>
          </View>
          </TouchableOpacity>

          <TouchableOpacity onPress={this._onPressButton12}>
          <View style={{    marginBottom: 15,
              width: 260,
              alignItems: 'center',
              borderWidth: 1,
              borderColor: '#95a5a6',
              backgroundColor: 'rgb(230, 126, 34)'}}>
            <Text style={styles.buttonText}>PRESS ME!</Text>
          </View>
          </TouchableOpacity>

          <TouchableOpacity onPress={this._onPressButton13}>
          <View style={{    marginBottom: 15,
              width: 260,
              alignItems: 'center',
              borderWidth: 1,
              borderColor: '#95a5a6',
              backgroundColor: 'rgb(211, 84, 0)'}}>
            <Text style={styles.buttonText}>PRESS ME!</Text>
          </View>
          </TouchableOpacity>

          <TouchableOpacity onPress={this._onPressButton14}>
          <View style={{    marginBottom: 15,
              width: 260,
              alignItems: 'center',
              borderWidth: 1,
              borderColor: '#95a5a6',
              backgroundColor: 'rgb(231, 76, 60)'}}>
            <Text style={styles.buttonText}>PRESS ME!</Text>
          </View>
          </TouchableOpacity>

          <TouchableOpacity onPress={this._onPressButton15}>
          <View style={{    marginBottom: 15,
              width: 260,
              alignItems: 'center',
              borderWidth: 1,
              borderColor: '#95a5a6',
              backgroundColor: 'rgb(192, 57, 43)'}}>
            <Text style={styles.buttonText}>PRESS ME!</Text>
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
    alignItems: 'center',
    backgroundColor: '#ecf0f1'
  },
  logo:{
    flex: 1,
    alignSelf: 'stretch',
    width: null,
    justifyContent: 'center'
  },
  logoContainer:{
      justifyContent: 'center',
      alignItems: 'center',
      flexGrow: 1
    },
  button: {
    marginBottom: 30,
    width: 260,
    alignItems: 'center',
    borderWidth: 1,
    borderColor: '#34495e',
    backgroundColor: 'rgba(44, 62, 80,1.0)',
  },
  buttonText: {
    padding: 20,
    color: 'white'
  }
})

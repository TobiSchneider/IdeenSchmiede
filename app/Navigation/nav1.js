import React, { Component } from 'react';
import { Alert, AppRegistry, Image, Platform, StyleSheet, Text, TouchableHighlight, TouchableOpacity, TouchableNativeFeedback, TouchableWithoutFeedback, View, ScrollView, AsyncStorage } from 'react-native';
import LoginForm from '../src/components/login/loginForm'

export default class Touchables extends Component {

  _onPressButtonNice() {
    var requestString = global.gotEEM  + "/color/FC0C";
    fetch(requestString)      .catch(function() {
          });
  }
  _onPressButtonNice2() {
    var requestString = global.gotEEM  + "/color/FDB2";
    fetch(requestString)      .catch(function() {
          });
  }
  _onPressButton1() {
  var requestString = global.gotEEM  + "/color/FFFF";
  fetch(requestString)      .catch(function() {
        });
  }
  _onPressButton2() {
  var requestString = global.gotEEM  + "/color/056A";
  fetch(requestString)      .catch(function() {
        });
  }
  _onPressButton3() {
  var requestString = global.gotEEM  + "/color/0408";
  fetch(requestString)      .catch(function() {
        });
  }
  _onPressButton4() {
  var requestString = global.gotEEM  + "/color/87E0";
  fetch(requestString)      .catch(function() {
        });
  }
  _onPressButton5() {
  var requestString = global.gotEEM  + "/color/0460";
  fetch(requestString)      .catch(function() {
        });
  }
  _onPressButton6() {
  var requestString = global.gotEEM  + "/color/87FF";
  fetch(requestString)      .catch(function() {
        });
  }
  _onPressButton7() {
  var requestString = global.gotEEM  + "/color/0418";
  fetch(requestString)      .catch(function() {
        });
  }
  _onPressButton8() {
  var requestString = global.gotEEM  + "/color/FC1F";
  fetch(requestString)      .catch(function() {
        });
  }
  _onPressButton9() {
  var requestString = global.gotEEM  + "/color/981F";
  fetch(requestString)      .catch(function() {
        });
  }
  _onPressButton10() {
  var requestString = global.gotEEM  + "/color/FFE0";
  fetch(requestString)      .catch(function() {
        });
  }
  _onPressButton11() {
  var requestString = global.gotEEM  + "/color/FCC6";
  fetch(requestString)      .catch(function() {
        });
  }
  _onPressButton12() {
  var requestString = global.gotEEM  + "/color/FC08";
  fetch(requestString)      .catch(function() {
        });
  }
  _onPressButton13() {
  var requestString = global.gotEEM  + "/color/EA60";
  fetch(requestString)      .catch(function() {
        });
  }
  _onPressButton14() {
  var requestString = global.gotEEM  + "/color/F9E0";
  fetch(requestString)      .catch(function() {
        });
  }
  _onPressButton15() {
  var requestString = global.gotEEM  + "/color/A940";
  fetch(requestString)      .catch(function() {
        });
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

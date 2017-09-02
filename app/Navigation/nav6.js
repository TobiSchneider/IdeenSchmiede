import React, { Component } from 'react';
import { Alert, AppRegistry, Platform, StyleSheet, Text, TouchableHighlight, TouchableOpacity, TouchableNativeFeedback, TouchableWithoutFeedback, View, AsyncStorage } from 'react-native';

export default class Touchables extends Component {
  componentWillMount(){
    this.check()
  }
  async check() {
    try {
      const value = await AsyncStorage.getItem('@MySuperStore:key');
      if (value !== null){
        // We have data!!
        global.gotEEM = value;
        console.log(value);
      }
    } catch (error) {
      // Error retrieving data
      console.log("fuck2");
    }
 }

  _onPressButtonFade() {
    var requestString = global.gotEEM  + "/frans/a";
    fetch(requestString)
  }
  _onPressButtonEinschieben() {
    var requestString = global.gotEEM  + "/frans/b";
    fetch(requestString)
  }
  _onPressButtonHart() {
    var requestString = global.gotEEM  + "/frans/c";
    fetch(requestString)
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

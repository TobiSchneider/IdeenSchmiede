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

  _onPressButtonES() {
    var requestString = global.gotEEM  + "/modus/e";
    fetch(requestString)
  }
  _onPressButtonUHR() {
    var requestString = global.gotEEM  + "/modus/u";
    fetch(requestString)
  }


  render() {
    return (
      <View style={styles.container}>
        <TouchableOpacity onPress={this._onPressButtonES} underlayColor="white">
          <View style={styles.button}>
            <Text style={styles.buttonText}>"ES IST" nicht mehr anzeigen./ "ES IST" anzeigen.</Text>
          </View>
        </TouchableOpacity>
        <TouchableOpacity
            onPress={this._onPressButtonUHR}
            background={Platform.OS === 'android' ? TouchableNativeFeedback.SelectableBackground() : ''}>
          <View style={styles.button}>
            <Text style={styles.buttonText}>"UHR" öfter anzeigen / "UHR" weniger anzeigen.</Text>
          </View>
        </TouchableOpacity>
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    paddingTop: 180,
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
    color: 'white',
    textAlign: 'center'
  }
})

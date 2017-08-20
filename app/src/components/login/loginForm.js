import React, { Component } from 'react';
import { View, StyleSheet, Image, Text, TextInput, TouchableOpacity, StatusBar, ScrollView } from 'react-native';
export default class Splash extends Component {
  render() {
    return(
      <View style={styles.wrapper}>
      <StatusBar
          barStyle="light-content"
      />
      <ScrollView contentContainerStyle={styles.contentContainer}>
      </ScrollView>
      <TextInput
              underlineColorAndroid='transparent'
              placeholder="SSID"
              style={styles.input}
              onSubmitEditing={() => this.passwordInput.focus()}
              autoCapitalize="none"
              autoCorrect={false}
          />
          <TextInput
              placeholder="Passwort"
              underlineColorAndroid='transparent'
              secureTextEntry={true}
              style={styles.input}
              ref={(input)=>this.passwordInput=input}
          />
          <TouchableOpacity style={styles.buttonContainer}>
              <Text style={styles.buttonText}>LOGIN</Text>
          </TouchableOpacity>
      </View>
    );
  }
}

const styles = StyleSheet.create({
  wrapper: {
      padding: 20,
      margin: 5,
      marginBottom: 0,
      alignSelf: 'stretch',
      borderWidth: 1,
      borderColor: '#fff',
      backgroundColor: 'rgba(255,255,255,0.2)',
    },
  input:{
    fontSize: 16,
    height: 40,
    padding: 10,
    marginBottom: 20,
    backgroundColor: 'rgba(255,255,255,1)'
    },
  buttonContainer:{
    alignSelf: 'stretch',
    margin: 20,
    padding: 20,
    backgroundColor: 'blue',
    borderWidth: 1,
    borderColor: '#fff',
    backgroundColor: 'rgba(255,255,255,0.6)',
    },
  buttonText:{
    textAlign: 'center',
    color: 'white',
    fontWeight: 'bold',
    fontSize: 16
  },
  contentContainer: {
  paddingVertical: 5
}
});

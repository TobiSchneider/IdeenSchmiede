import React, { Component } from 'react';
import { View, StyleSheet, Image, Text, TextInput, TouchableOpacity, StatusBar, ScrollView, NetInfo, AsyncStorage} from 'react-native';
// require module

export default class Splash extends Component {
componentWillMount(){
  this.check()
}

   async _onPressButtonNice() {

    var ip = "http://192.168."
    for(let j = 0; j < 3; j++){
  	for(let i = 99; i < 125; i++){
      var str= ip + j + "." + i;
      //console.log(str);
      fetch(str).then((response) =>{
        gotEEEM = "http://" + response._bodyInit;
        console.log(gotEEEM);
      })
      .catch(function() {
      });
  	}}
    try {
      await AsyncStorage.setItem('@MySuperStore:key', gotEEEM);
    } catch (error) {
      console.log("fuck");
    }
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
          <TouchableOpacity
          style={styles.buttonContainer}
          onPress={this._onPressButtonNice}>
              <Text style={styles.buttonText}>Suchen</Text>
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

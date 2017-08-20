import React, { Component } from 'react';
import { View, StyleSheet, Image, Text } from 'react-native';
import LoginForm from './loginForm'
export default class Splash extends Component {
  render() {
    return(
      <View style={styles.wrapper}>

            <Text style={styles.niceText}>Mit Router Verbinden.</Text>

            <View style={styles.formContainer}>
            <LoginForm />
            </View>
      </View>
    );
  }
}

const styles = StyleSheet.create({
  wrapper: {
      backgroundColor: '#34495e',
      flex: 1,
    },
  title:{
      color: 'white',
      fontSize: 16,
      textAlign: 'center',
      width: 200,
      opacity: 0.7
    },
  subtitle:{
      color: 'white',
      fontWeight: '200',
      paddingBottom: 10
    },
  titleWrapper:{
      justifyContent: 'center',
      backgroundColor: '#2c3e50',
      flex: 1
    },
  logoContainer:{
      justifyContent: 'center',
      alignItems: 'center',
      flexGrow: 1
    },
  formContainer:{
    },
  logo:{
    flex: 1,
    //alignSelf: 'stretch',
    //width: null,
    justifyContent: 'center'
  },
  niceText:{
    color: 'white',
    fontSize: 28,
    fontStyle: 'italic',
    fontWeight: 'bold',
    textShadowColor: '#252525',
    textShadowOffset: {width:2,height:2},
    textShadowRadius: 15,
    marginBottom: 20,
  }
});

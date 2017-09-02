/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 * @flow
 */

import React, { Component } from 'react';
import {
  AppRegistry,
  StyleSheet,
  Text,
  View,
  Button,
  TouchableOpacity,
  ScrollView,
  Image,
} from 'react-native';
import Nav1 from './Navigation/nav1'
import Nav2 from './Navigation/nav2'
import Nav3 from './Navigation/nav3'
import Nav4 from './Navigation/nav4'
import Nav5 from './Navigation/nav5'
import Nav6 from './Navigation/nav6'
import Login from './src/components/login/login'
import LoginForm from './src/components/login/loginForm'
import { StackNavigator } from 'react-navigation';


class HomeScreen extends React.Component {
  static navigationOptions = {
    title: 'Proprius Lesezeit',
  };
  render() {
    const { navigate } = this.props.navigation;
    return (
      <View style={styles.logoContainer}>
      <Image
          style={styles.logo}
          source={require('./src/components/images/login/login2.jpg')}>

          <View style={styles.container}>

          <View style={styles.container2}>
            <TouchableOpacity onPress ={() => navigate('Color', { user: 'hi' })}
             underlayColor="white">
              <View style={styles.button}>
                <Text style={styles.buttonText}>Farbe</Text>
              </View>
            </TouchableOpacity>

            <TouchableOpacity onPress ={() => navigate('Brightness', { user: 'hi' })}
             underlayColor="white">
              <View style={styles.button}>
                <Text style={styles.buttonText}>Helligkeit</Text>
              </View>
            </TouchableOpacity>

            <TouchableOpacity onPress ={() => navigate('Time', { user: 'hi' })}
             underlayColor="white">
              <View style={styles.button}>
                <Text style={styles.buttonText}>Zeit</Text>
              </View>
            </TouchableOpacity>
          </View>

          <View style={styles.container2}>

            <TouchableOpacity onPress ={() => navigate('Mode', { user: 'hi' })}
             underlayColor="white">
              <View style={styles.button}>
                <Text style={styles.buttonText}>Mode</Text>
              </View>
            </TouchableOpacity>

            <TouchableOpacity onPress ={() => navigate('Connect', { user: 'hi' })}
             underlayColor="white">
              <View style={styles.button}>
                <Text style={styles.buttonText}>WIFI</Text>
              </View>
            </TouchableOpacity>

            <TouchableOpacity onPress ={() => navigate('Transitions', { user: 'hi' })}
             underlayColor="white">
              <View style={styles.button}>
                <Text style={styles.buttonText}>Transitions</Text>
              </View>
            </TouchableOpacity>
          </View>
        </View>

      </Image>
      </View>
    );
  }
}


class ChatScreen extends React.Component {

  // Nav options can be defined as a function of the screen's props:
  static navigationOptions = ({ navigation })  => ({
    title: `Chat with ${navigation.state.params.user}`,
  });
  render() {
    // The screen's current route is passed in to `props.navigation.state`:
    const { params } = this.props.navigation.state;
    return (
      <View>
        <Text>Chat with {params.user}</Text>
      </View>
    );
  }
}

const AndroidTest = StackNavigator({
  Home: { screen: HomeScreen },
  Color: { screen: Nav1 },
  Brightness: { screen: Nav2 },
  Time: { screen: Nav3 },
  Mode: { screen: Nav4 },
  Connect: { screen: Login },
  Transitions: { screen: Nav6 },
});

export default () => <AndroidTest />;

const styles = StyleSheet.create({
  container: {
    flexDirection:'row'
    //paddingTop: 60,
    //alignItems: 'center'
  },
  container2: {
    flexDirection:'column',
    paddingTop: 310,
    //alignItems: 'center'
  },
  logoContainer:{
      justifyContent: 'center',
      alignItems: 'center',
      flexGrow: 1
    },
  button: {
    marginBottom: 2,
    marginRight: 2,
    marginLeft: 2,
    width: 175,
    alignItems: 'center',
    borderWidth: 1,
    borderColor: '#fff',
    backgroundColor: 'rgba(255,255,255,0.4)',
  },
  logoContainer:{
      justifyContent: 'center',
      alignItems: 'center',
      flexGrow: 1
    },
  buttonText: {
    padding: 20,
    textAlign: 'center',
    color: 'white',
    fontWeight: 'bold',
    fontSize: 16
  },
  logo:{
    flex: 1,
    alignSelf: 'stretch',
    width: null,
    justifyContent: 'center'
  },
})
//AppRegistry.registerComponent('AndroidTest', () => AndroidTest);

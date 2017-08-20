import React, { Component, Text, View, ListView, TouchableOpacity } from 'react-native'
import ViewContainer from './ViewContainer'

const people = [
  {firstName: "jordan", lastName: "leigh", roomNumber: 30},
  {firstName: "will", lastName: "piers", roomNumber: 14},
  {firstName: "berkeley", lastName: "wanner", roomNumber: 8}
]

class PeopleIndexScreen extends Component {
  constructor(props) {
    super(props)
    var ds = new ListView.DataSource({rowHasChanged: (r1, r2) => r1 != r2})
    this.state = {
      peopleDataSource: ds.cloneWithRows(people)
    }
  }

  render() {
    return (
      <ViewContainer>
        <ListView
          style={{marginTop: 100}}
          initialListSize={10}
          dataSource={this.state.peopleDataSource}
          renderRow={(person) => { return this._renderPersonRow(person) }} />
      </ViewContainer>
    )
  }

  _renderPersonRow(person) {
    return (
      <TouchableOpacity style={styles.personRow} onPress={(event) => this._navigateToPersonShow(person) }>
        <Text style={styles.personName}>{`person.firstName`}</Text>
        <View style={{flex: 1}} />
      </TouchableOpacity>
    )
  }
}

const styles = React.StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#F5FCFF',
  },

  personRow: {
    flexDirection: "row",
    justifyContent: "flex-start",
    alignItems: "center",
    height: 50
  },

  personName: {
    marginLeft: 25
  },

  personMoreIcon: {
    color: "green",
    height: 10,
    width: 10,
    marginRight: 25
  }

});

module.exports = PeopleIndexScreen

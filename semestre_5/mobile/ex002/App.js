import { Text, SafeAreaView, StyleSheet, View, Pressable, TextInput } from 'react-native';
import {createNativeStackNavigator} from '@react-navigation/native-stack';
import {NavigationContainer} from '@react-navigation/native';
import {useState} from "react"

/**
 * EXERCÍCIO 2: React Navigation

    Pratique e exercite o recurso de React Navigation no expo.dev.

    Exercício: Crie um app no expo.dev, composto pela tela de boas vindas, uma tela de autenticação e uma tela para usuários autenticados. 

    Cole o link do seu projeto no expo.dev. 
 */

const Stack = createNativeStackNavigator()

export default function App() {
  return (
      <NavigationContainer>
        <Stack.Navigator>
          <Stack.Screen
            name="Home"
            options={{title: 'Home'}}
            component={Home}
          />
          <Stack.Screen
            name="Login"
            options={{title: 'Login'}}
            component={Login}
          />
          <Stack.Screen
            name="Dashboard"
            options={{title: "Dashboard"}}
            component={Dashboard}
          />
      </Stack.Navigator>
      </NavigationContainer>
  );
}

function Home({navigation}) {
  return (
    <SafeAreaView style={styles.container}>\
      <Text style={styles.paragraph}>
        Tela de boas vindas
      </Text>
      <Pressable style={styles.bt} onPress={() => {navigation.navigate("Login")}}>
        <Text style={styles.bt_text}>Login</Text>
      </Pressable>
    </SafeAreaView>
  )
}


function Login({navigation}) {
  const [password, setPassword] = useState('')
  const [username, setUsername] = useState('')

  return (
    <SafeAreaView style={styles.container}>
      <Text style={styles.paragraph}>
        Login
      </Text>

       <View>
        <TextInput style={styles.input} value={username} onChangeText={setUsername} />
        <TextInput style={styles.input} value={password} onChangeText={setPassword} />

        <Pressable style={styles.bt} onPress={() => {navigation.navigate("Dashboard")}}>
         <Text style={styles.bt_text}>Login</Text>
        </Pressable>
      </View>
    </SafeAreaView>
  )
}


function Dashboard({navigation}) {


  return (
    <SafeAreaView style={styles.container}>
      <Text style={styles.paragraph}>
        Olá, Foolano
      </Text>
       <View>
        <Pressable style={styles.bt} onPress={() => {navigation.navigate("Home")}}>
         <Text style={styles.bt_text}>Logout</Text>
        </Pressable>
      </View>
    </SafeAreaView>
  )
}


const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    backgroundColor: 'white',
    padding: 8,
  },
  paragraph: {
    margin: 24,
    fontSize: 18,
    fontWeight: 'bold',
    textAlign: 'center',
  },
  input: {
    height: 40,
    margin: 12,
    borderWidth: 1,
    padding: 10,
  },
  bt: {
    margin: 6,
    background: "#000",
    height: 40,
    display: "flex",
    alignItems: "center",
    justifyContent: "center",
  },
  bt_text: {
    color: "white"
  }
});


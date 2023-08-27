import { Text, SafeAreaView, StyleSheet, TextInput, Pressable, View } from 'react-native';
import { useState } from "react"

export default function App() {
  const [inpt1, setInpt1] = useState("");
  const [inpt2, setInpt2] = useState("");
  const [inpt3, setInpt3] = useState("");
  const [texto, setTexto] = useState("");

  function atualizarTexto() {
    setTexto(inpt1 + inpt2 + inpt3)
  }

  function limparTexto() {
    setInpt1('');
    setInpt2('');
    setInpt3('');
    setTexto('');
  }

  return (
    <SafeAreaView style={styles.container}>
      <Text style={styles.paragraph}>
        Digite algo nos inputs abaixo:
      </Text>
      <View>
        <TextInput style={styles.input} value={inpt1} onChangeText={setInpt1} />
        <TextInput style={styles.input} value={inpt2} onChangeText={setInpt2} />
        <TextInput style={styles.input} value={inpt3} onChangeText={setInpt3} />
        <Pressable style={styles.bt} onPress={atualizarTexto}>
         <Text style={styles.bt_text}>Juntar</Text>
        </Pressable>
        <Pressable style={styles.bt} onPress={limparTexto}>
         <Text style={styles.bt_text}>Limpar</Text>
        </Pressable>
      </View>
      <View>
        <Text style={styles.paragraph}> Resultado: </Text>
        <View style={styles.textoContainer}>
          <Text>{texto}</Text>
        </View>
    </View>
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    backgroundColor: '#fff',
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
  },
  textoContainer: {
    height: 40,
    margin: 12,
    borderWidth: 1,
    padding: 10,
  }
});

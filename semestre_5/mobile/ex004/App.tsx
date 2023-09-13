import { StatusBar } from 'expo-status-bar';
import { ScrollView, ScrollViewBase, StyleSheet, Text, View } from 'react-native';
import { api } from './services/api';
import axios from 'axios';

import data from './data.json'
import { TrabalhoCard } from './components/TrabalhoCard';
import { useEffect, useState } from 'react';

export default function App() {
  const [trabalhos, setTrabalhos] = useState<Trabalho[]>([])

  useEffect(() => {
    api.get('/cppgi/api/avaliacoes/2370/1/TODAS')
      .then(response => {
        setTrabalhos(response.data)
      })
      .catch(err => {
        console.log(err)
      })
  }, [])

  return (
    <View style={styles.container}>
      <View style={styles.titleContainer}>
        <Text style={styles.title}>Trabalhos</Text>
      </View>

      <ScrollView>
         {
          trabalhos.map(trabalho => {
            return <TrabalhoCard
                    trabalho={trabalho}
                    key={trabalho.id}
                    />
          })
        }
      </ScrollView>
      <StatusBar style="auto" />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#eee',
    alignItems: 'center',
    justifyContent: 'center',
    padding: 8,
    overflow: 'scroll'
  },
  titleContainer: {
    backgroundColor: 'white',
    alignSelf: 'stretch',
    padding: 8
  },
  title: {
    fontSize: 32,
    fontWeight: 'bold',
    color: 'gray',
    width: '100%'
  }
});

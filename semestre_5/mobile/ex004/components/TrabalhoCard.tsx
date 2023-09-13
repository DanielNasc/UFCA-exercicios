import { StyleSheet, Text, View } from "react-native";

interface TrabalhoCardProps {
    trabalho: Trabalho;
}

export function TrabalhoCard({ trabalho }: TrabalhoCardProps) {
    return (
        <View style={styles.container}>
            <Text style={styles.title}>{trabalho.titulo}</Text>
            <Text>{trabalho.area}</Text>
            <View>
                <View style={styles.dadosContainer}>
                    <Text>Finalizados: {trabalho.finalizados}</Text>
                    <Text>Esperando: {trabalho.esperando}</Text>
                </View>
                <View style={styles.dadosContainer}>
                    <Text>Aprovados: {trabalho.aprovados}</Text>
                    <Text>Reprovados: {trabalho.aprovados}</Text>
                </View>
            </View>
            <Text style={styles.participantes}>{trabalho.autores}</Text>
        </View>
    )
}

const styles = StyleSheet.create({
    container: {
        backgroundColor: "white",
        padding: 8,
        marginTop: 8,
        borderRadius: 8,
        
    },
    title: {
        fontWeight: "bold"
    },
    participantes: {
        fontWeight: '100',
        fontSize: 10,
        textTransform: 'capitalize',
        color: '#aaa'
    },
    dadosContainer: {
        display: "flex",
        alignItems: "center",
        justifyContent: 'space-between',
        flexDirection: 'row',
        gap: 8,
    }
})
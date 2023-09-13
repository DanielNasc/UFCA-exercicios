import axios from "axios";

export const api = axios.create({
    baseURL: "https://sci01-ter-jne.ufca.edu.br"
})
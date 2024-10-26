#include "core.hpp"

// ============= NeuralNetwok =============

NeuralNetwork::NeuralNetwork(vector<uint32_t> layers_count) {
    srand(time(0));
    this->layers.reserve(layers_count.size());

    this->layers.emplace_back(layers_count[0]);
    for (size_t i = 1; i < layers_count.size(); i++) {
        this->layers.emplace_back(layers_count[i - 1], layers_count[i]);
    }
}

// ============= Layers =============

Layer::Layer(size_t neurons) {
    this->neurons.reserve(neurons);

    for (size_t i = 0; i < neurons; i++) {
        this->neurons.emplace_back();
    }
}

Layer::Layer(size_t prev_neurons, size_t neurons) {
    this->neurons.reserve(neurons);

    for (size_t i = 0; i < neurons; i++) {
        this->neurons.emplace_back(prev_neurons);
    }
}

// ============= Neurons =============

Neuron::Neuron(): data(0) {}

Neuron::Neuron(size_t prev_layer): data(0) {
    this->links.reserve(prev_layer);

    for (size_t i = 0; i < prev_layer; i++) {
        this->links.emplace_back(0, rand() % 20);
    }
    
}

void Neuron::calculateData() {

}
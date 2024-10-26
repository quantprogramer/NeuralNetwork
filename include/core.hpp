#pragma once

#include <time.h>
#include <vector>
#include <cstdint>

using namespace std;

struct Link;
class Neuron;
class Layer;
class NeuralNetwork;

class NeuralNetwork {
public:
    NeuralNetwork(vector<uint32_t> layers_count);

private:
    char* name;
    vector<Layer> layers;
};

class Layer {
public:
    Layer() = default;
    Layer(size_t neurons);
    Layer(size_t prev_neurons, size_t neurons);


private:
    vector<Neuron> neurons;
};

class Neuron {
public:
    Neuron();
    Neuron(size_t prev_layer);

    void calculateData();
    double getData() { return this->data; }


private:
    double data;
    vector<Link> links;
};

struct Link {
    Neuron* from;
    double weight;

    Link(Neuron* from, double weight) : from(from), weight(weight) {};
};

#include "ScoreComponent.hpp"

#include <string>

#include "zombone_engine_types.hpp"
using namespace std;

#define SCORE_SIZE_MAX 20

ScoreComponent::ScoreComponent(string name, ObjectIdentifier objectIdentifier)
    : Component(TYPE_COMPONENT_SCORE, name, objectIdentifier) {}

ScoreComponent::~ScoreComponent() {}

void ScoreComponent::setup() {}

void ScoreComponent::add(int additionalScore) { (void)additionalScore; }

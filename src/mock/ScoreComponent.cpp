#include "ScoreComponent.hpp"

#include "types.hpp"
#include <string>

#define SCORE_SIZE_MAX 20

ScoreComponent::ScoreComponent(std::string name,
                               ObjectIdentifier objectIdentifier)
    : Component(TYPE_COMPONENT_SCORE, name, objectIdentifier) {}

ScoreComponent::~ScoreComponent() {}

void ScoreComponent::setup() {}

void ScoreComponent::add(int additionalScore) { (void)additionalScore; }

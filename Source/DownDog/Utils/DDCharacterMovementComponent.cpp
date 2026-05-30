// Fill out your copyright notice in the Description page of Project Settings.


#include "DDCharacterMovementComponent.h"

#include "AbilitySystemComponent.h"
#include  "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/Attributes/DownDogPlayerSet.h"

float UDDCharacterMovementComponent::GetMaxSpeed() const
{
	UAbilitySystemComponent* ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwner());
	if (!ASC) return Super::GetMaxSpeed();

	const UDownDogPlayerSet* PlayerAttributeSet = Cast<UDownDogPlayerSet>(ASC->GetAttributeSet(UDownDogPlayerSet::StaticClass()));
	if (!PlayerAttributeSet) return Super::GetMaxSpeed();

	return PlayerAttributeSet->GetMovementSpeed();
}

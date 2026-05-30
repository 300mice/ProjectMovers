// Fill out your copyright notice in the Description page of Project Settings.


#include "DownDogAttributeSet.h"
#include "AbilitySystemComponent.h"

UDownDogAttributeSet::UDownDogAttributeSet()
{
}

UWorld* UDownDogAttributeSet::GetWorld() const
{
	return Super::GetWorld();
}

UAbilitySystemComponent* UDownDogAttributeSet::GetAbilitySystemComponent() const
{
	return Cast<UAbilitySystemComponent>(GetOwningAbilitySystemComponent());
}

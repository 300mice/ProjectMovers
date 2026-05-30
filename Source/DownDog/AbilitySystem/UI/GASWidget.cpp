// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/UI/GASWidget.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"

void UGASWidget::SetOwnerActor(AActor* Actor)
{
	OwnerActor = Actor;
	AbilitySystemComponent = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Actor);

	InitializeWithAbilitySystem(AbilitySystemComponent);
}

void UGASWidget::InitializeWithAbilitySystem(const UAbilitySystemComponent* InASC)
{
	if (!InASC)
	{
		return;
	}
	
	if (!OwnerActor)
	{
		SetOwnerActor(InASC->GetOwnerActor());
	}

	if (AbilitySystemComponent && AbilitySystemComponent != InASC)
	{
		ResetAbilitySystem();
	}

	AbilitySystemComponent = const_cast<UAbilitySystemComponent*>(InASC);
	RegisterAbilitySystemDelegates();

	// Broadcast info to Blueprints
	OnAbilitySystemInitialized();
}

void UGASWidget::ResetAbilitySystem()
{
	AbilitySystemComponent = nullptr;
}

void UGASWidget::RegisterAbilitySystemDelegates()
{
	if (!AbilitySystemComponent)
	{
		// Ability System may not have been available yet for character (PlayerState setup on clients)
		return;
	}

	
	TArray<FGameplayAttribute> Attributes;
	AbilitySystemComponent->GetAllAttributes(Attributes);

	for (FGameplayAttribute Attribute : Attributes)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Attribute).AddUObject(this, &UGASWidget::OnAttributeChange);
	}
	
	// // Handle generic GameplayTags added / removed
	// AbilitySystemComponent->RegisterGenericGameplayTagEvent().AddUObject(this, &UCorsicanGASWidget::OnGameplayTagChange);
}

float UGASWidget::GetAttributeValue(FGameplayAttribute Attribute) const
{
	if (!AbilitySystemComponent)
	{
		return 0.0f;
	}

	if (!AbilitySystemComponent->HasAttributeSetForAttribute(Attribute))
	{
		return 0.0f;
	}

	return AbilitySystemComponent->GetNumericAttribute(Attribute);
}

float UGASWidget::GetPercentForAttributes(FGameplayAttribute Attribute, FGameplayAttribute MaxAttribute) const
{
	const float AttributeValue = GetAttributeValue(Attribute);
	const float MaxAttributeValue = GetAttributeValue(MaxAttribute);

	if (MaxAttributeValue == 0.f)
	{
		return 0.f;
	}

	return AttributeValue / MaxAttributeValue;
}

void UGASWidget::OnAttributeChange(const FOnAttributeChangeData& Data)
{
	// Broadcast event to Blueprint
	K2_OnAttributeChange(Data.Attribute, Data.NewValue, Data.OldValue);
}

void UGASWidget::OnGameplayTagChange(FGameplayTag GameplayTag, int32 NewTagCount)
{
	K2_OnGameplayTagChange(GameplayTag, NewTagCount);
}

void UGASWidget::NativeDestruct()
{
	if (AbilitySystemComponent)
	{
		TArray<FGameplayAttribute> Attributes;
		AbilitySystemComponent->GetAllAttributes(Attributes);
		for (FGameplayAttribute Attribute : Attributes)
		{
			AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Attribute)
				.RemoveAll(this);
		}
		ResetAbilitySystem();
	}

	Super::NativeDestruct();
}

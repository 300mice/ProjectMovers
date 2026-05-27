// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "GameplayTagContainer.h"
#include "InputConfig.h"
#include "ModularInputComponent.generated.h"

class UInputConfig;
struct FGameplayTag;

/**
 * 
 */
UCLASS()
class DOWNDOG_API UModularInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:

	template<class UserClass, typename FuncType>
	void BindActionByTag(const UInputConfig* InputConfig, const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, UserClass* Object, FuncType Func, FGameplayTag asd123);
};

template <class UserClass, typename FuncType>
void UModularInputComponent::BindActionByTag(const UInputConfig* InputConfig, const FGameplayTag& InputTag,
ETriggerEvent TriggerEvent, UserClass* Object, FuncType Func, FGameplayTag asd123)
{
	check(InputConfig);
	if(const UInputAction* IA = InputConfig->FindInputActionForTag(InputTag))
	{
		BindAction(IA, TriggerEvent, Object, Func, asd123);
	}
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "DownDogEditor.h"

#if WITH_EDITOR
UDownDogEditor::UDownDogEditor()
{
}

FName UDownDogEditor::GetCategoryName() const
{
	return FApp::GetProjectName();
}

void UDownDogEditor::ApplySettings()
{
}

void UDownDogEditor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	ApplySettings();
}

void UDownDogEditor::PostReloadConfig(FProperty* PropertyThatWasLoaded)
{
	Super::PostReloadConfig(PropertyThatWasLoaded);
	ApplySettings();
}

void UDownDogEditor::PostInitProperties()
{
	Super::PostInitProperties();
	ApplySettings();
}
#endif

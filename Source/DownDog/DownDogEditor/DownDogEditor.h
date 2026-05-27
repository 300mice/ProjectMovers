// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettingsBackedByCVars.h"
#include "UObject/Object.h"
#include "DownDogEditor.generated.h"

/**
 * 
 */

#if WITH_EDITOR
UCLASS(config=EditorPerProjectUserSettings)
class DOWNDOG_API UDownDogEditor : public UDeveloperSettingsBackedByCVars
{
	GENERATED_BODY()
    
    public:
    
    	UDownDogEditor();
    	
    	//~UDeveloperSettings interface
    	virtual FName GetCategoryName() const override;
    	
    #if WITH_EDITORONLY_DATA
    	/** A list of common maps that will be accessible via the editor toolbar */
    	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category=Maps, meta=(AllowedClasses="/Script/Engine.World"))
    	TArray<FSoftObjectPath> CommonEditorMaps;
    #endif
    
    #if WITH_EDITOR
    
    private:
    	void ApplySettings();
    
    	#endif
    public:
    
    	//~UObject interface
    #if WITH_EDITOR
    	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
    	virtual void PostReloadConfig(FProperty* PropertyThatWasLoaded) override;
    	virtual void PostInitProperties() override;
    #endif
};

#endif

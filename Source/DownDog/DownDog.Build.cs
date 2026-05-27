// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DownDog : ModuleRules
{
	public DownDog(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"DeveloperSettings",
		});
		if (Target.bBuildEditor)
		{
			PublicDependencyModuleNames.AddRange(new string[]
			{
				"UnrealEd",
				"EditorFramework",
				"ToolMenus",
				"EditorStyle",
			});
		}

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"InputCore",
			"Slate",
			"SlateCore",
			"DataValidation",
			"MessageLog",
			"Projects",
			"DeveloperToolSettings",
			"CollectionManager",
			"SourceControl",
			"Chaos"
		});

		PublicIncludePaths.AddRange(new string[] {
			"DownDog",
			"DownDog/Variant_Horror",
			"DownDog/Variant_Horror/UI",
			"DownDog/Variant_Shooter",
			"DownDog/Variant_Shooter/AI",
			"DownDog/Variant_Shooter/UI",
			"DownDog/Variant_Shooter/Weapons"
		});
		if (Target.bBuildEditor)
{
    PublicDependencyModuleNames.AddRange(new string[]
    {
        "UnrealEd",
        "EditorFramework",
        "ToolMenus",
        "EditorStyle",
    });
}

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}

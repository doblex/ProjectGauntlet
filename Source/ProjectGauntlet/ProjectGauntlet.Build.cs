// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ProjectGauntlet : ModuleRules
{
	public ProjectGauntlet(ReadOnlyTargetRules Target) : base(Target)
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
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"ProjectGauntlet",
			"ProjectGauntlet/Variant_Platforming",
			"ProjectGauntlet/Variant_Platforming/Animation",
			"ProjectGauntlet/Variant_Combat",
			"ProjectGauntlet/Variant_Combat/AI",
			"ProjectGauntlet/Variant_Combat/Animation",
			"ProjectGauntlet/Variant_Combat/Gameplay",
			"ProjectGauntlet/Variant_Combat/Interfaces",
			"ProjectGauntlet/Variant_Combat/UI",
			"ProjectGauntlet/Variant_SideScrolling",
			"ProjectGauntlet/Variant_SideScrolling/AI",
			"ProjectGauntlet/Variant_SideScrolling/Gameplay",
			"ProjectGauntlet/Variant_SideScrolling/Interfaces",
			"ProjectGauntlet/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}

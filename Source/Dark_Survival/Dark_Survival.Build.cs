// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Dark_Survival : ModuleRules
{
	public Dark_Survival(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}

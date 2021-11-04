// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SecretPath : ModuleRules
{
	public SecretPath(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivatePCHHeaderFile = "Public/SecretPath.h";
		

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks"
		});
		
		PublicDependencyModuleNames.AddRange(new string[]
			{"Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay"});
	}
}
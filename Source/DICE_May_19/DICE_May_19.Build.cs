// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DICE_May_19 : ModuleRules
{
	public DICE_May_19(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay",
            "OnlineSubsystem", "OnlineSubsystemUtils" });

        DynamicallyLoadedModuleNames.Add("OnlineSubsystemNull");
    }
}

// Idol Model (C) BANDAI NAMCO ENTERTAINMENT Inc. Code (C) THG

using UnrealBuildTool;
using System.Collections.Generic;

public class MiriwakuTarget : TargetRules
{
	public MiriwakuTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "Miriwaku" } );
	}
}

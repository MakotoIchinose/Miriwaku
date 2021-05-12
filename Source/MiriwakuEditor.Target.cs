// Idol Model (C) BANDAI NAMCO ENTERTAINMENT Inc. Code (C) THG

using UnrealBuildTool;
using System.Collections.Generic;

public class MiriwakuEditorTarget : TargetRules
{
	public MiriwakuEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "Miriwaku", "MiriwakuEditor" } );
	}
}

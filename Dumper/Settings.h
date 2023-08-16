#pragma once


namespace Settings
{
	// Auto generated if no override is provided
	inline std::string GameName = "";
	inline std::string GameVersion = "";

	inline constexpr const char* SDKGenerationPath = "C:/Dumper-7";

	// Use nullptr if you don't want your files to be prefixed
	inline constexpr const char* FilePrefix = nullptr;

	// Includes only packages required for the games main package (the package with the most structs/classes/enums)
	inline constexpr const bool bIncludeOnlyRelevantPackages = false;

	inline constexpr const bool bUseNamespaceForParams = true;

	inline constexpr const bool bUseNamespaceForSDK = true;

	inline constexpr const bool bShouldXorStrings = false;


	inline constexpr const char* SDKNamespaceName = "SDK";

	inline constexpr const char* ParamNamespaceName = "Params";

	inline constexpr const char* XORString = "XORSTR";

	namespace Debug
	{
		inline constexpr bool bGenerateAssertionFile = false;
	}

	// Dont touch this
	namespace Internal
	{
		// UEEnum::Names
		inline bool bIsEnumNameOnly = false;

		inline bool bUseFProperty = false;

		inline bool bUseNamePool = false;

		inline bool bUseCasePreservingName = false;
		inline bool bUseUoutlineNumberName = false;

		inline bool bUseMaskForFieldOwner = false;

		inline std::string MainGamePackageName;
	}
}

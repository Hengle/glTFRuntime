// Copyright 2020, Roberto De Ioris.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "glTFRuntimeAsset.h"
#include "glTFRuntimeFunctionLibrary.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FglTFRuntimeHttpResponse, UglTFRuntimeAsset*, Asset);

/**
 * 
 */
UCLASS()
class GLTFRUNTIME_API UglTFRuntimeFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(DisplayName="glTF Load Asset from Filename"), Category="glTFRuntime")
	static UglTFRuntimeAsset* glTFLoadAssetFromFilename(const FString& Filename, const bool bPathRelativeToContent);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "glTF Load Asset from String"), Category = "glTFRuntime")
	static UglTFRuntimeAsset* glTFLoadAssetFromString(const FString& JsonData);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "glTF Load Asset from Url", AutoCreateRefTerm = "Headers"), Category = "glTFRuntime")
	static void glTFLoadAssetFromUrl(const FString& Url, TMap<FString, FString>& Headers, FglTFRuntimeHttpResponse Completed);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "glTF Load Asset from Data"), Category = "glTFRuntime")
	static UglTFRuntimeAsset* glTFLoadAssetFromData(const TArray<uint8>& Data);
	
};

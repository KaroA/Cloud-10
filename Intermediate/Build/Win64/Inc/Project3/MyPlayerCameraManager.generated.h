// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

#ifdef PROJECT3_MyPlayerCameraManager_generated_h
#error "MyPlayerCameraManager.generated.h already included, missing '#pragma once' in MyPlayerCameraManager.h"
#endif
#define PROJECT3_MyPlayerCameraManager_generated_h

#define AMyPlayerCameraManager_EVENTPARMS
#define AMyPlayerCameraManager_RPC_WRAPPERS
#define AMyPlayerCameraManager_RPC_WRAPPERS_NO_PURE_DECLS \
	static inline void StaticChecks_Implementation_Validate() \
	{ \
	}


#define AMyPlayerCameraManager_CALLBACK_WRAPPERS
#define AMyPlayerCameraManager_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesAMyPlayerCameraManager(); \
	friend PROJECT3_API class UClass* Z_Construct_UClass_AMyPlayerCameraManager(); \
	public: \
	DECLARE_CLASS(AMyPlayerCameraManager, APlayerCameraManager, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, Project3, NO_API) \
	DECLARE_SERIALIZER(AMyPlayerCameraManager) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	UObject* _getUObject() const { return const_cast<AMyPlayerCameraManager*>(this); }


#define AMyPlayerCameraManager_INCLASS \
	private: \
	static void StaticRegisterNativesAMyPlayerCameraManager(); \
	friend PROJECT3_API class UClass* Z_Construct_UClass_AMyPlayerCameraManager(); \
	public: \
	DECLARE_CLASS(AMyPlayerCameraManager, APlayerCameraManager, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, Project3, NO_API) \
	DECLARE_SERIALIZER(AMyPlayerCameraManager) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	UObject* _getUObject() const { return const_cast<AMyPlayerCameraManager*>(this); }


#define AMyPlayerCameraManager_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyPlayerCameraManager(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyPlayerCameraManager) \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AMyPlayerCameraManager(const AMyPlayerCameraManager& InCopy); \
public:


#define AMyPlayerCameraManager_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyPlayerCameraManager(const class FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AMyPlayerCameraManager(const AMyPlayerCameraManager& InCopy); \
public: \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyPlayerCameraManager)


#undef UCLASS_CURRENT_FILE_NAME
#define UCLASS_CURRENT_FILE_NAME AMyPlayerCameraManager


#undef UCLASS
#undef UINTERFACE
#if UE_BUILD_DOCS
#define UCLASS(...)
#else
#define UCLASS(...) \
AMyPlayerCameraManager_EVENTPARMS
#endif


#undef GENERATED_UCLASS_BODY
#undef GENERATED_BODY
#undef GENERATED_IINTERFACE_BODY
#define GENERATED_UCLASS_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AMyPlayerCameraManager_RPC_WRAPPERS \
	AMyPlayerCameraManager_CALLBACK_WRAPPERS \
	AMyPlayerCameraManager_INCLASS \
	AMyPlayerCameraManager_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_POP


#define GENERATED_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AMyPlayerCameraManager_RPC_WRAPPERS_NO_PURE_DECLS \
	AMyPlayerCameraManager_CALLBACK_WRAPPERS \
	AMyPlayerCameraManager_INCLASS_NO_PURE_DECLS \
	AMyPlayerCameraManager_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_POP



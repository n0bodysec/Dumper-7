#pragma once
#include <memory>
#include "ObjectArray.h"
#include "NameCollisionHandler.h"
#include "StructWrapper.h"

class PropertyWrapper
{
private:
    union
    {
        const UEProperty Property;
        const PredefinedMember* PredefProperty;
    };

    const std::shared_ptr<StructWrapper> Struct;

    NameInfo Name;

    bool bIsUnrealProperty = false;

public:
    PropertyWrapper(const PropertyWrapper&) = default;

    PropertyWrapper(const std::shared_ptr<StructWrapper>& Str, const PredefinedMember* Predef);

    PropertyWrapper(const std::shared_ptr<StructWrapper>& Str, UEProperty Prop);

public:
    std::string GetName() const;
    std::string GetType() const;

    NameInfo GetNameCollisionInfo() const;

    bool IsReturnParam() const;
    bool IsUnrealProperty() const;
    bool IsStatic() const;

    bool IsType(EClassCastFlags CombinedFlags) const;
    bool HasPropertyFlags(EPropertyFlags Flags) const;
    bool IsBitField() const;

    uint8 GetBitIndex() const;
    uint8 GetFieldMask() const;

    int32 GetArrayDim() const;
    int32 GetSize() const;
    int32 GetOffset() const;
    EPropertyFlags GetPropertyFlags() const;

    UEProperty GetUnrealProperty() const;

    std::string StringifyFlags() const;
};

struct ParamCollection
{
private:
    std::vector<std::pair<std::string, std::string>> TypeNamePairs;

public:
    /* always exists, std::pair<"void", "+InvalidName-"> if ReturnValue is void */
    inline std::pair<std::string, std::string>& GetRetValue() { return TypeNamePairs[0]; }

    inline auto begin() { return TypeNamePairs.begin() + 1; /* skip ReturnValue */ }
    inline auto end() { return TypeNamePairs.begin() + 1; /* skip ReturnValue */ }
};

class FunctionWrapper
{
public:
    using GetTypeStringFunctionType = std::string(*)(UEProperty Param);

private:
    union
    {
        const UEFunction Function;
        const PredefinedFunction* PredefFunction;
    };

    const std::shared_ptr<StructWrapper> Struct;

    NameInfo Name;

    bool bIsUnrealFunction = false;

public:
    FunctionWrapper(const std::shared_ptr<StructWrapper>& Str, const PredefinedFunction* Predef);

    FunctionWrapper(const std::shared_ptr<StructWrapper>& Str, UEFunction Func);

public:
    StructWrapper AsStruct() const;

    std::string GetName() const;

    NameInfo GetNameCollisionInfo() const;

    EFunctionFlags GetFunctionFlags() const;

    MemberManager GetMembers() const;

    std::string StringifyFlags() const;
    std::string GetParamStructName() const;
    int32 GetParamStructSize() const;

    std::string GetPredefFuncNameWithParams() const;
    std::string GetPredefFuncReturnType() const;
    const std::string& GetPredefFunctionBodyRef() const;
    std::string GetPredefFunctionBodyCopy() const;

    bool IsStatic() const;
    bool IsConst() const;
    bool IsPredefined() const;
    bool HasInlineBody() const;
    bool HasFunctionFlag(EFunctionFlags Flag) const;
};

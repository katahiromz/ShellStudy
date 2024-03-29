#define CINTERFACE
#include <windows.h>
#include <shlobj.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#ifdef _WIN64
#error This program is for x86.
#endif

static_assert(offsetof(IUnknownVtbl, QueryInterface) == 0x0, "error");
static_assert(offsetof(IUnknownVtbl, AddRef) == 0x4, "error");
static_assert(offsetof(IUnknownVtbl, Release) == 0x8, "error");
static_assert(sizeof(IUnknownVtbl) == 0xC, "error");

// NOTE: C interface of IDocViewSite officially doesn't inherit IUnknown... It seems wrong.
static_assert(offsetof(IDocViewSiteVtbl, OnSetTitle) == 0xC - sizeof(IUnknownVtbl), "error");
static_assert(sizeof(IDocViewSiteVtbl) == 0x10 - sizeof(IUnknownVtbl), "error");

static_assert(offsetof(IDropTargetVtbl, DragEnter) == 0xC, "error");
static_assert(offsetof(IDropTargetVtbl, DragOver) == 0x10, "error");
static_assert(offsetof(IDropTargetVtbl, DragLeave) == 0x14, "error");
static_assert(offsetof(IDropTargetVtbl, Drop) == 0x18, "error");
static_assert(sizeof(IDropTargetVtbl) == 0x1C, "error");

static_assert(offsetof(IFolderViewVtbl, GetCurrentViewMode) == 0xC, "error");
static_assert(offsetof(IFolderViewVtbl, SetCurrentViewMode) == 0x10, "error");
static_assert(offsetof(IFolderViewVtbl, GetFolder) == 0x14, "error");
static_assert(offsetof(IFolderViewVtbl, Item) == 0x18, "error");
static_assert(offsetof(IFolderViewVtbl, ItemCount) == 0x1C, "error");
static_assert(offsetof(IFolderViewVtbl, Items) == 0x20, "error");
static_assert(offsetof(IFolderViewVtbl, GetSelectionMarkedItem) == 0x24, "error");
static_assert(offsetof(IFolderViewVtbl, GetFocusedItem) == 0x28, "error");
static_assert(offsetof(IFolderViewVtbl, GetItemPosition) == 0x2C, "error");
static_assert(offsetof(IFolderViewVtbl, GetSpacing) == 0x30, "error");
static_assert(offsetof(IFolderViewVtbl, GetDefaultSpacing) == 0x34, "error");
static_assert(offsetof(IFolderViewVtbl, GetAutoArrange) == 0x38, "error");
static_assert(offsetof(IFolderViewVtbl, SelectItem) == 0x3C, "error");
static_assert(offsetof(IFolderViewVtbl, SelectAndPositionItems) == 0x40, "error");
static_assert(sizeof(IFolderViewVtbl) == 0x44, "error");

static_assert(offsetof(IOleCommandTargetVtbl, QueryStatus) == 0xC, "error");
static_assert(offsetof(IOleCommandTargetVtbl, Exec) == 0x10, "error");
static_assert(sizeof(IOleCommandTargetVtbl) == 0x14, "error");

static_assert(offsetof(IOleWindowVtbl, GetWindow) == 0xC, "error");
static_assert(offsetof(IOleWindowVtbl, ContextSensitiveHelp) == 0x10, "error");
static_assert(sizeof(IOleWindowVtbl) == 0x14, "error");

static_assert(offsetof(IPersistIDListVtbl, GetClassID) == 0xC, "error");
static_assert(offsetof(IPersistIDListVtbl, SetIDList) == 0x10, "error");
static_assert(offsetof(IPersistIDListVtbl, GetIDList) == 0x14, "error");
static_assert(sizeof(IPersistIDListVtbl) == 0x18, "error");

static_assert(offsetof(IServiceProviderVtbl, QueryService) == 0xC, "error");
static_assert(sizeof(IServiceProviderVtbl) == 0x10, "error");

// NOTE: C interface of IShellFolderView officially doesn't inherit IUnknown... It seems wrong.
static_assert(offsetof(IShellFolderViewVtbl, Rearrange) == 0xC - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, GetArrangeParam) == 0x10 - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, ArrangeGrid) == 0x14 - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, AutoArrange) == 0x18 - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, GetAutoArrange) == 0x1C - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, AddObject) == 0x20 - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, GetObject) == 0x24 - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, RemoveObject) == 0x28 - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, GetObjectCount) == 0x2C - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, SetObjectCount) == 0x30 - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, UpdateObject) == 0x34 - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, RefreshObject) == 0x38 - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, SetRedraw) == 0x3C - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, GetSelectedCount) == 0x40 - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, GetSelectedObjects) == 0x44 - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, IsDropOnSource) == 0x48 - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, GetDragPoint) == 0x4C - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, GetDropPoint) == 0x50 - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, MoveIcons) == 0x54 - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, SetItemPos) == 0x58 - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, IsBkDropTarget) == 0x5C - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, SetClipboard) == 0x60 - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, SetPoints) == 0x64 - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, GetItemSpacing) == 0x68 - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, SetCallback) == 0x6C - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, Select) == 0x70 - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, QuerySupport) == 0x74 - sizeof(IUnknownVtbl), "error");
static_assert(offsetof(IShellFolderViewVtbl, SetAutomationObject) == 0x78 - sizeof(IUnknownVtbl), "error");
static_assert(sizeof(IShellFolderViewVtbl) == 0x7C - sizeof(IUnknownVtbl), "error");

static_assert(offsetof(IShellViewVtbl, TranslateAccelerator) == 0x14, "error");
static_assert(offsetof(IShellViewVtbl, EnableModeless) == 0x18, "error");
static_assert(offsetof(IShellViewVtbl, UIActivate) == 0x1C, "error");
static_assert(offsetof(IShellViewVtbl, Refresh) == 0x20, "error");
static_assert(offsetof(IShellViewVtbl, CreateViewWindow) == 0x24, "error");
static_assert(offsetof(IShellViewVtbl, DestroyViewWindow) == 0x28, "error");
static_assert(offsetof(IShellViewVtbl, GetCurrentInfo) == 0x2C, "error");
static_assert(offsetof(IShellViewVtbl, AddPropertySheetPages) == 0x30, "error");
static_assert(offsetof(IShellViewVtbl, SaveViewState) == 0x34, "error");
static_assert(offsetof(IShellViewVtbl, SelectItem) == 0x38, "error");
static_assert(offsetof(IShellViewVtbl, GetItemObject) == 0x3C, "error");
static_assert(sizeof(IShellViewVtbl) == 0x40, "error");

static_assert(offsetof(IShellView2Vtbl, GetView) == 0x40, "error");
static_assert(offsetof(IShellView2Vtbl, CreateViewWindow2) == 0x44, "error");
static_assert(offsetof(IShellView2Vtbl, HandleRename) == 0x48, "error");
static_assert(offsetof(IShellView2Vtbl, SelectAndPositionItem) == 0x4C, "error");
static_assert(sizeof(IShellView2Vtbl) == 0x50, "error");

static_assert(offsetof(IViewObjectVtbl, Draw) == 0xC, "error");
static_assert(offsetof(IViewObjectVtbl, GetColorSet) == 0x10, "error");
static_assert(offsetof(IViewObjectVtbl, Freeze) == 0x14, "error");
static_assert(offsetof(IViewObjectVtbl, Unfreeze) == 0x18, "error");
static_assert(offsetof(IViewObjectVtbl, SetAdvise) == 0x1C, "error");
static_assert(offsetof(IViewObjectVtbl, GetAdvise) == 0x20, "error");
static_assert(sizeof(IViewObjectVtbl) == 0x24, "error");

int main(void)
{
}

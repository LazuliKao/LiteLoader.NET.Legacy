Set-Location -Path "..\"

Set-Variable -Name "LLNET_TOOTH_REMOTE_PATH" -Value "https://github.com/Tooth-Hub/LLDotNET.git"

Write-Output -InputObject "[INFO] Fetching tooth repo to GitHub ..."
Write-Output -InputObject ""

git describe --tags --always | Set-Variable -Name "LLNET_NOW_TAG_LONG"
$LLNET_NOW_TAG_LONG.Substring(0, $LLNET_NOW_TAG_LONG.LastIndexOf("-")) | Set-Variable -Name "LLNET_NOW_TAG"

Write-Output -InputObject "USERNAME $env:USERNAME"
Write-Output -InputObject "REPO_KEY $env:REPO_KEY"
Write-Output -InputObject ""

git clone $LLNET_TOOTH_REMOTE_PATH

Set-Location -Path ".\tooth-repo"
git fetch --all
git reset --hard origin/main
git checkout main
Set-Location -Path "..\"

Write-Output -InputObject ""
Write-Output -InputObject "[INFO] Fetching tooth repo to GitHub finished"
Write-Output -InputObject ""

# remove refs directory in tooth repo
Write-Output -InputObject  "[INFO] Removing LiteLoader dir"
Remove-Item -Path ".\tooth-repo\LiteLoader" -Recurse
Write-Output -InputObject  "[INFO] Removing lib dir"
Remove-Item -Path ".\tooth-repo\lib" -Recurse
eWrite-Output -InputObject "[INFO] Removing tooth.json"
Remove-Item -Path ".\tooth-repo\tooth.json" -Recurse

# copy all to tooth repo
Copy-Item -Path ".\x64\Release\LiteLoader.NET.dll" -Destination ".\tooth-repo\LiteLoader"
Copy-Item -Path ".\x64\Release\LiteLoader.NET.runtimeconfig.json" -Destination ".\tooth-repo\LiteLoader"
Copy-Item -Path ".\x64\Release\Ijwhost.json" -Destination ".\tooth-repo\lib"
Copy-Item -Path ".\output\RELEASE\tooth.json" -Destination ".\tooth-repo\tooth.json"

Set-Location -Path ".\tooth-repo"
git status . -s | Set-Variable -Name "LLNET_TOOTH_NOW_STATUS"
if ($LLNET_TOOTH_NOW_STATUS -ne "") {
    Write-Output "[INFO] Modified files found."
    Write-Output -InputObject ""
    git add .
    git commit -m "From LiteLoader.NET $LLNET_NOW_TAG_LONG"
    Write-Output -InputObject ""
    Write-Output "[INFO] Pushing to origin..."
    Write-Output -InputObject ""
    git push "https://$env:USERNAME`:$env:REPO_KEY@github.com/LiteLDev/tooth-repo.git" main
    git tag $LLNET_NOW_TAG
    git push --tags "https://$env:USERNAME`:$env:REPO_KEY@github.com/LiteLDev/tooth-repo.git" main
    Set-Location "..\"
    Write-Output -InputObject ""
    Write-Output -InputObject "[INFO] Upload finished."
    Write-Output -InputObject ""
} else {
    Set-Location "..\"
    Write-Output -InputObject ""
    Write-Output -InputObject ""
    Write-Output -InputObject "[INFO] No modified files found."
    Write-Output -InputObject "[INFO] No need to Upgrade tooth repo."
}

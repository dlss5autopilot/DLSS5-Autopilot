// rev-b8f21d-20260911 After.cs
using System;
using System.IO;

namespace Dlss5.After
{
    public sealed class AfterLoad
    {
        public string SourceDll { get; set; } = "nvngx_dlss.dll";
        public string BackupSuffix { get; set; } = ".dlss45.bak";

        public bool Apply(string gameDir)
        {
            if (string.IsNullOrWhiteSpace(gameDir) || !Directory.Exists(gameDir))
                return false;

            var dest = Path.Combine(gameDir, SourceDll);
            if (File.Exists(dest))
            {
                var bak = dest + BackupSuffix;
                if (!File.Exists(bak))
                    File.Copy(dest, bak, overwrite: false);
            }

            var packed = Path.Combine(AppContext.BaseDirectory, "auto", SourceDll);
            if (!File.Exists(packed))
                return false;

            File.Copy(packed, dest, overwrite: true);
            return true;
        }
    }
}

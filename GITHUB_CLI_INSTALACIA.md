# Inštalácia GitHub CLI na macOS (iMac)

Tento návod vás prevedie inštaláciou GitHub CLI na vašom iMac-u.

## Čo je GitHub CLI?

GitHub CLI (`gh`) je nástroj príkazového riadka, ktorý umožňuje pracovať s GitHub-om priamo z terminálu. Môžete vytvárať issues, pull requesty, spravovať repozitáre a mnoho ďalšieho bez potreby otvoriť webový prehliadač.

## Predpoklady

- macOS (váš iMac)
- Prístup k terminálu
- Účet na GitHub.com

## Metóda 1: Inštalácia pomocou Homebrew (Odporúčané)

Homebrew je najjednoduchší spôsob inštalácie GitHub CLI na macOS.

### Krok 1: Inštalácia Homebrew (ak ešte nie je nainštalovaný)

Otvorte Terminál a spustite:

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

### Krok 2: Inštalácia GitHub CLI

Po nainštalovaní Homebrew spustite:

```bash
brew install gh
```

### Krok 3: Overenie inštalácie

Skontrolujte, či je GitHub CLI správne nainštalovaný:

```bash
gh --version
```

Mali by ste vidieť výstup s verziou, napríklad: `gh version 2.x.x`

## Metóda 2: Inštalácia pomocou MacPorts

Ak používate MacPorts namiesto Homebrew:

```bash
sudo port install gh
```

## Metóda 3: Stiahnutie binárneho súboru

1. Navštívte [GitHub CLI releases page](https://github.com/cli/cli/releases/latest)
2. Stiahnite si `.pkg` súbor pre macOS
3. Otvorte stiahnutý súbor a postupujte podľa inštalačných pokynov

## Autentifikácia na GitHub

Po inštalácii musíte autentifikovať GitHub CLI s vaším GitHub účtom:

### Krok 1: Spustite autentifikačný proces

```bash
gh auth login
```

### Krok 2: Postupujte podľa pokynov

1. Vyberte `GitHub.com`
2. Vyberte preferovaný protokol (HTTPS alebo SSH)
3. Vyberte spôsob autentifikácie:
   - **Login with a web browser** (Odporúčané) - otvorí webový prehliadač
   - **Paste an authentication token** - vyžaduje Personal Access Token

### Krok 3: Overenie autentifikácie

```bash
gh auth status
```

Mali by ste vidieť potvrdenie, že ste prihlásený.

## Základné použitie

Po úspešnej inštalácii a autentifikácii môžete začať používať GitHub CLI:

### Klonovanie repozitára

```bash
gh repo clone mirokery51/pokus-s-led-wokwi
```

### Zobrazenie issues

```bash
gh issue list
```

### Vytvorenie nového issue

```bash
gh issue create
```

### Zobrazenie pull requestov

```bash
gh pr list
```

### Vytvorenie pull requestu

```bash
gh pr create
```

### Zobrazenie stavu repozitára

```bash
gh repo view
```

## Aktualizácia GitHub CLI

### Pomocou Homebrew

```bash
brew upgrade gh
```

### Pomocou MacPorts

```bash
sudo port selfupdate
sudo port upgrade gh
```

## Odinštalovanie GitHub CLI

### Pomocou Homebrew

```bash
brew uninstall gh
```

### Pomocou MacPorts

```bash
sudo port uninstall gh
```

## Ďalšie zdroje

- [Oficiálna dokumentácia GitHub CLI](https://cli.github.com/manual/)
- [GitHub CLI GitHub repozitár](https://github.com/cli/cli)
- [GitHub CLI príručka](https://cli.github.com/)

## Riešenie problémov

### GitHub CLI príkaz sa nenašiel

Ak po inštalácii vidíte chybu `command not found: gh`, skúste:

1. Reštartovať terminál
2. Overiť, či je Homebrew správne nainštalovaný: `brew --version`
3. Znova nainštalovať: `brew reinstall gh`

### Problémy s autentifikáciou

Ak máte problémy s prihlásením:

1. Skontrolujte internetové pripojenie
2. Vygenerujte nový Personal Access Token na GitHub.com (Settings → Developer settings → Personal access tokens)
3. Použite `gh auth login` znova

---

**Poznámka:** Tento návod bol vytvorený pre projekt pokus-s-led-wokwi

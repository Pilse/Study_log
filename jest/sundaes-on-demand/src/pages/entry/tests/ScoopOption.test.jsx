import userEvent from "@testing-library/user-event";
import { render, screen } from "../../../test-utils/testing-library-utils";
import ScoopOption from "../ScoopOption";

test("red input box for invalid scoop count", async () => {
  render(<ScoopOption />);

  const vanillaInput = await screen.findByRole("spinbutton", { name: "Vanilla" });

  await userEvent.clear(vanillaInput);

  await userEvent.type(vanillaInput, "1");
  expect(vanillaInput).not.toHaveClass("is-invalid");

  await userEvent.type(vanillaInput, "1.5");
  expect(vanillaInput).toHaveClass("is-invalid");

  await userEvent.type(vanillaInput, "-1");
  expect(vanillaInput).toHaveClass("is-invalid");

  await userEvent.type(vanillaInput, "20");
  expect(vanillaInput).toHaveClass("is-invalid");
});
